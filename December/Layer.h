#ifndef LAYER_H
#define LAYER_H

#include <Core.h>
#include <Events/Event.h>

namespace December {
    class Layer
    {
        public:
            Layer(const std::string &name = "Layer");
            virtual ~Layer();

            virtual void OnAttach() {}
            virtual void OnDetach() {}
            virtual void OnUpdate() {}
            virtual void OnEvent(Event &event) {}

            inline const std::string &get_name() const { return debug_name; }

        protected:
            std::string debug_name;
        private:
    };
}

#endif // LAYER_H
