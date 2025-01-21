#ifndef APPLICATION_H
#define APPLICATION_H

namespace December
{
     class __declspec(dllexport) Application
    {
    public:
        Application() = default;
        virtual ~Application() = default;
        void run();

    };

    Application* CreateApplication();
}

#endif // APPLICATION_H
