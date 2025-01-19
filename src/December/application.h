#ifndef APPLICATION_H
#define APPLICATION_H

namespace December
{
     class __declspec(dllexport) Application
    {
    public:
        Application() {}
        virtual ~Application() {}
        void run() {
            while (true);
        }

    };

    Application* CreateApplication();
}

#endif // APPLICATION_H
