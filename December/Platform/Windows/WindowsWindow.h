#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include <Window.h>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <Logger.h>

namespace December {
    class WindowsWindow : public December::Window
    {
        public:
            WindowsWindow(const December::WindowProps& props);
            virtual ~WindowsWindow();

            void onUpdate() override;

            inline unsigned int GetWidth() const override { return data.width; }
            inline unsigned int GetHeight() const override { return data.height; }

            inline void SetEventCallback(const EventCallBackFn& callback) override { data.EventCallBack = callback; }
            void SetVSync(bool enabled) override;
            bool IsVSync() const override;


            sf::RenderWindow* GetNativeWindow() const { return window; }

        protected:
            virtual void Init(const December::WindowProps& props);
            virtual void Shutdown();
        private:
            sf::RenderWindow* window;
            sf::Event event;

            struct WindowData
            {
                std::string Title;
                unsigned int width, height;
                bool VSync;

                EventCallBackFn EventCallBack;
            };

            WindowData data;
    };
}
#endif // WINDOWSWINDOW_H
