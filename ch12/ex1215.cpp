#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct connection
{
    std::string ip;
    int port;
    connection(std::string _ip, int _port) : ip(_ip), port(_port){ }
};

struct destination
{
    std::string ip;
    int port;
    destination(std::string _ip, int _port) : ip(_ip), port(_port) { }
};

connection connect(destination* pDest)
{
    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection(" << pConn->ip << ":" << pConn->port << ")" << std::endl;
    return *pConn;
}

void disconnect(connection *pConn)
{
    std::cout << "connection close(" << pConn->ip << ":" << pConn->port << ")" << std::endl;
}

void end_connection(connection *pConn)
{
    disconnect(pConn);
}

void f(destination &d)
{
    connection conn = connect(&d);
    std::shared_ptr<connection> p(&conn, [](connection *p) { disconnect(p); });
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main()
{
    destination dest("202.118.176.67", 3316);    
    f(dest);
    return 0;
}
