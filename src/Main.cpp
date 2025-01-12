#include "donut/app/ApplicationBase.h"
#include "donut/app/imgui_renderer.h"

using namespace donut;

class UIRenderer : public app::ImGui_Renderer {

};

int main() {
  log::ConsoleApplicationMode();
  log::info("Hello");

  app::DeviceManager *Device =
      app::DeviceManager::Create(nvrhi::GraphicsAPI::VULKAN);

  app::DeviceCreationParameters DeviceParameters;

  if (!Device->CreateWindowDeviceAndSwapChain(DeviceParameters, "Window Bro")) {
    log::fatal("Unable to jawn at all");
    return 1;
  }

  Device->RunMessageLoop();

  Device->Shutdown();
  delete Device;

  return 0;
}