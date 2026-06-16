#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

class BoostHUD : public BakkesMod::Plugin::BakkesModPlugin, public BakkesMod::Plugin::PluginSettingsWindow
{
    void onLoad() override
    {
        gameWrapper->RegisterDrawable([this](CanvasWrapper canvas) {
            if (!gameWrapper->IsInGame()) return;
            auto server = gameWrapper->GetCurrentGameState();
            if (!server) return;
            auto boost = server.GetBoost();

            Vector2 barPos = { 960 - 150, 50 };
            Vector2 barSize = { 300, 30 };
            canvas.SetColor(0, 0, 0, 180);
            canvas.FillRect(barPos, barSize);

            float pct = boost / 100.0f;
            canvas.SetColor(0, 255, 0, 200);
            canvas.FillRect(barPos, { barSize.X * pct, barSize.Y });

            canvas.SetColor(255, 255, 255, 255);
            canvas.DrawRect(barPos, barSize);

            canvas.SetPosition(barPos + Vector2{ barSize.X/2, barSize.Y/2 });
            canvas.SetColor(255, 255, 255, 255);
            canvas.DrawString(std::to_string((int)boost) + "%", 2.0f, 2.0f, true, true);
        });
    }

    void onUnload() override {}
    void RenderSettings() override {}
    std::string GetPluginName() override { return "Boost HUD"; }
    void SetImGuiContext(uintptr_t ctx) override {}
};

BAKKESMOD_PLUGIN(BoostHUD, "Boost HUD plugin", "1.0", PLUGINTYPE_FREEPLAY)
