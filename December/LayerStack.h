#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include "Core.h"
#include "Layer.h"

#include <vector>

namespace December {
    class LayerStack
    {
        public:
            LayerStack();
            virtual ~LayerStack();

            void PushLayer(Layer *layer);
            void PushOverlay(Layer *overlay);
            void PopLayer(Layer *layer);
            void popOverlay(Layer *overlay);

            std::vector<Layer*>::iterator begin() { return Layers.begin(); }
            std::vector<Layer*>::iterator end() { return Layers.end(); }
        protected:

        private:
            std::vector<Layer*> Layers;
            std::vector<Layer*>::iterator LayerInsert;
    };
}
#endif // LAYERSTACK_H
