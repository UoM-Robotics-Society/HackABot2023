# Python 3 server example
from http.server import BaseHTTPRequestHandler, HTTPServer
import time

hostName = "localhost"
serverPort = 8080

class MyServer(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        self.wfile.write(bytes("""
        <html>
            <head>
            <title>
            MONA and Ball locations
            </title>
            </head>
            <body>
            <h1>MONA and Ball Locations.
            </h1><br>C1,1580,966,2.96

            <br>G43,231,535,1.59

            <br>G42,1641,519,-0.05

            <br>M8,507,518,-0.4

            <br>M7,1293,372,-0.42

            <br>C0,294,65,-1.5

            <br>B,911,585,0

            </body>
        </html>
        """, "utf-8"))

if __name__ == "__main__":        
    webServer = HTTPServer((hostName, serverPort), MyServer)
    print("Server started http://%s:%s" % (hostName, serverPort))

    try:
        webServer.serve_forever()
    except KeyboardInterrupt:
        pass

    webServer.server_close()
    print("Server stopped.")