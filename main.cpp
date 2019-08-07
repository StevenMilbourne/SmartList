#include <iostream>
#include <string>
#include <vector>
#include "pistache/endpoint.h"
#include "List.h"
#include "ListItem.h"
#include "ListUtil.h"

using namespace Pistache;

auto list = std::make_unique<List>();

class UpdateHandler : public Http::Handler {
public:

    HTTP_PROTOTYPE(UpdateHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) override{
        UNUSED(request);
        
        if (request.resource() == "/smartlist") {
            if (request.query().has("q")) {
                std::string str = request.query().get("q").get();
                std::cout << str << std::endl;
                updateList(list, str);
                list->display();
                response.send(Pistache::Http::Code::Ok, str);
            }
            
            else{
                response.send(Pistache::Http::Code::Ok, "String was empty");
            }
        }
        
        
        else if (request.resource() == "/smartmirror") {
            Http::serveFile(response, "../html/smartmirror.html", MIME(Text, Html));
        }
        
        
        else if (request.resource() == "/json") {
            response.headers().add<Pistache::Http::Header::ContentType>(MIME(Application, Json));
            response.send(Http::Code::Ok, list->jsonify());
        }
        
        
        else if(request.resource() == "/reset") {
            list->reset();
            response.send(Pistache::Http::Code::Ok, "List Reset");
        }
        
        else{
            
            response.send(Pistache::Http::Code::Ok, "ok");
            
        }
    }
};


int main() {
    Http::listenAndServe<UpdateHandler>("*:1066");
}