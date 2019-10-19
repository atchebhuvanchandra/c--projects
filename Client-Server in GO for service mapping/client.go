
package main
 
import (
	"fmt"
	"net"
	"strings"
	"bufio"
	"os"
	"encoding/binary"
	"strconv"
)
 
func CheckError(err error) {
    if err  != nil {
        fmt.Println("Error: " , err)
    }
}



func main() {
    ServerAddr,err := net.ResolveUDPAddr("udp","137.148.205.255:24836")
    CheckError(err)
    
    LocalAddr, err := net.ResolveUDPAddr("udp", ":0")
    CheckError(err)
 
    CLNS, err := net.ListenUDP("udp", LocalAddr)
    CheckError(err)
 
    message := []byte("GET CISBANK")
    _,err =CLNS.WriteToUDP([]byte(message), ServerAddr)

	buf:=make([]byte,1500)
	n,remAddr,err :=CLNS.ReadFromUDP(buf)

    if err != nil {
            fmt.Println(message, err)
	}
	revdmsg:=strings.Split(string(buf[0:n]),":")

	fmt.Println("Received ",revdmsg, " from ",remAddr)
	IPaddr := revdmsg[0]
	Portnumber := revdmsg[1]
	tempaddr, err :=net.LookupAddr(IPaddr)
	addr := strings.Join(tempaddr,".")
	  
	for{
			conn, err := net.Dial("tcp", addr+":"+Portnumber )
			CheckError(err)
			reader:=bufio.NewReader(os.Stdin)
			fmt.Print("Enter Query \n");
       
			clientInput:=in.ReadString()
			if (clientInput[0]=="query"){
			dbquery:=uint32(1000)
			binary.Write(conn,binary.BigEndian,dbquery)
			accNum,_:=strconv.Atoi(clientInput[1][0:len(clientInput[1])-1])
			accNum32:=uint32(accNum)
			binary.Write(conn,binary.BigEndian,accNum32)
			msg,_:=bufio.NewReader(conn).ReadString('\n')
			fmt.Println(msg)
			return;
		} 
		else if (clientInput[0]=="update")
		{
			dbquery:=uint32(1001)
			binary.Write(conn,binary.BigEndian,dbquery)
			accNum,_:=strconv.Atoi(clientInput[1])
			accNum32:=uint32(accNum)
			binary.Write(conn,binary.BigEndian,accNum32)
			value,_:=strconv.ParseFloat(clientInput[2][0:len(clientInput[2])-1],32)
			var value32 float32=float32(value)
			binary.Write(conn,binary.BigEndian,value32)
			msg,_:=bufio.NewReader(conn).ReadString('\n')
			fmt.Print("\nMessage from server :"+msg)
			return;
		}
		defer conn.Close()
	}
    defer CLNS.Close()
}
