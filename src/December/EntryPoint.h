#ifndef _ENTRYPOINT_H
#define _ENTRYPOINT_H

extern December::Application* December::CreateApplication();

int main(int argc, char** argv)
{
    auto app = December::CreateApplication();
    app->run();
    delete app;
}
#endif // _ENTRYPOINT_H
