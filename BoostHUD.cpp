// BoostHUD.cpp - Displays boost amount and bar on screen
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"
#include "version.h"

class BoostHUD : public BakkesMod::Plugin::BakkesModPlugin, public BakkesMod::Plugin::PluginSettingsWindow
{
    void onLoad() override
    {
        // Register to draw on screen
        gameWrapper->RegisterDrawable([this](CanvasWrapper canvas) {
            if (!gameWrapper->IsInGame()) return;
            auto server = gameWrapper->GetCurrentGameState();
            if (!server) return;
            auto boost = server.GetBoost(); // returns boost amount 0-100
            // Background bar
            Vector2 barPos = { 960 - 150, 50 };
            Vector2 barSize = { 300, 30 };
            canvas.SetColor(0, 0, 0, 180);
            canvas.FillRect(barPos, barSize);
            // Filled bar
            float pct = boost / 100.0f;
            canvas.SetColor(0, 255, 0, 200);
            canvas.FillRect(barPos, { barSize.X * pct, barSize.Y });
            // Border
            canvas.SetColor(255, 255, 255, 255);
            canvas.DrawRect(barPos, barSize);
            // Text
            canvas.SetPosition(barPos + Vector2{ barSize.X/2, barSize.Y/2 });
            canvas.SetColor(255, 255, 255, 255);
            canvas.DrawString(std::to_string((int)boost) + "%", 2.0f, 2.0f, true, true);
        });
    }
    void onUnload() override {}
    void RenderSettings() override {} // no settings
    std::string GetPluginName() override { return "Boost HUD"; }
    void SetImGuiContext(uintptr_t ctx) override {}
};

// Plugin export
BAKKESMOD_PLUGIN(BoostHUD, "Boost HUD plugin", "1.0", PLUGINTYPE_FREEPLAY)
