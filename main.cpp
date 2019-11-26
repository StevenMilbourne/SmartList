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
        
        if (request.resource() == "/") {
            if (request.method() == Http::Method::Post ) {
				if (request.query().has("q")){
					std::string str = request.query().get("q").get();
					std::cout << str << std::endl;
					updateList(list, str);
					list->display();
					response.send(Http::Code::Ok, str);
				}
				else{
					response.send(Http::Code::Bad_Request, "Bad Request. Possibly Due To Empty String");
				}

            }
            else if (request.method() == Http::Method::Get){
				Http::serveFile(response, "../html/smartmirror.html", MIME(Text, Html));
			}
			
			else if(request.method() == Http::Method::Delete) {
				list->reset();
				response.send(Pistache::Http::Code::Ok, "List Reset");
			}
			
            else{
                response.send(Http::Code::Method_Not_Allowed, "Method Not Allowed");
            }
        }

        
        else if (request.resource() == "/json") {
            response.headers().add<Pistache::Http::Header::ContentType>(MIME(Application, Json));
            response.send(Http::Code::Ok, list->jsonify());
        }
        
        
        else{
            response.send(Http::Code::Bad_Request, "Bad Request");
        }
    }
};


int main() {
    Http::listenAndServe<UpdateHandler>("*:1066");
}
