#include <December.h>

class EVEAPP : public December::Application {
    public:
        EVEAPP() {
        }
        ~EVEAPP() {
        }
};

December::Application* December::CreateApplication()
{
    return new EVEAPP();
}
