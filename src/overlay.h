#include <string>
#include <stdint.h>
#include "imgui.h"
#include "overlay_params.h"
#include "iostats.h"

extern std::string engineName;
struct frame_stat {
   uint64_t stats[OVERLAY_PARAM_ENABLED_MAX];
};

struct swapchain_stats {
   uint64_t n_frames;
   enum overlay_param_enabled stat_selector;
   double time_dividor;
   struct frame_stat stats_min, stats_max;
   struct frame_stat frames_stats[200];

   ImFont* font1 = nullptr;
   std::string time;
   double fps;
   struct iostats io;
   int total_cpu;
};

struct hud_update {
   uint64_t last_present_time;
   unsigned n_frames_since_update;
   uint64_t last_fps_update;
};

void position_layer(struct overlay_params& params, ImVec2 window_size, unsigned width, unsigned height);
void render_imgui(swapchain_stats& data, struct overlay_params& params, ImVec2& window_size, unsigned width, unsigned height);
void update_hud_info(struct swapchain_stats& sw_stats, struct overlay_params& params, struct hud_update& hud_updates, std::string gpu);