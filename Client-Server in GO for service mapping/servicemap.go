C
package main
 
import (
    "fmt"
    "net"
    "os"
    "strings"
)
 
var servermap map[string]string

/* A Simple function to verify error */
func CheckError(err error) {
    if err  != nil {
        fmt.Println("Error: " , err)
        os.Exit(0)
    }
}
 

/*func sendResponse(conn *net.UDPConn, addr *net.UDPAddr) 
{
    _,err := conn.WriteToUDP([]byte("From server: Registration OK "+string(servermap["PUT"])), addr)
    if err != nil 
	{
        fmt.Printf("Couldn't send response %v", err)
    }
}*/


func main() 
{
    /* Lets prepare a address at any address at port 24836*/   
    ServerAddr,err := net.ResolveUDPAddr("udp",":24836")    // UDP port 2(last four of student num)
    CheckError(err)
    
	/*servermap=make(map[string]string)*/
    /* Now listen (misleading in Go;  actually bind at selected port */
    ServerCLNS, err := net.ListenUDP("udp", ServerAddr)
    CheckError(err)
    defer ServerCLNS.Close()
    buf := make([]byte, 1024)
	bufOK := []byte("Registration OK")
	bufFrom := []byte ("Service Requested from  ")
    
	for 
	{
        buffV,addr,err := ServerCLNS.ReadFromUDP(buf)
		buffV=25 // buffer size increased manually here,change later
        fmt.Println("Received from ",addr.IP.String(),string(buf[0:buffV]))
        receivedMSG := strings.Split(string(buf[0:buffV])," ")
		map_addr := make(map[string]string)
		map_addr[receivedMSG[1]] = (string(addr.IP.String()) + ":" + receivedMSG[2])
		ServerCLNS.WriteToUDP(bufOK, addr)// nwriting to server
		CheckError(err)
		//buffV,addr,err = ServerCLNS.ReadFromUDP(buf)  Redundunt
		strRCV := strings.Split(string(buf[0:buffV])," ")
	    value, ok := map_addr[strRCV[1]]	
		if ok {
			//fmt.Println("asked service is present in map")
			bufClient := []byte(value)
			//fmt.Println("are we sending server's ip and port? ", string(bufClient) )
			ServerCLNS.WriteToUDP(bufClient[0:buffV],addr)
		} 
		else {
		fmt.Println("Service not registered!")
		}

		strSend := strings.Split(string(buf[0:buffV])," ")
		fmt.Println("(client) Received  from ",addr.IP.String(),string(strSend[0]),string(strSend[1]))
		
		ServerCLNS.WriteToUDP(bufFrom[0:buffV],addr)
        if err != nil {
            fmt.Println("Error: ",err)
        } 
     
    }
}
