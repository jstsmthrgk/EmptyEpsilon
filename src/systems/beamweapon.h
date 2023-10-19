#pragma once

#include "ecs/system.h"
#include "systems/rendering.h"
#include "systems/radar.h"
#include "components/beamweapon.h"

class BeamWeaponSystem : public sp::ecs::System, public Render3DInterface, public RenderRadarInterface<BeamWeaponSys, 20, RadarRenderSystem::FlagShortRange>
{
public:
    BeamWeaponSystem();

    void update(float delta) override;

    void render3D(sp::ecs::Entity e) override;
    void renderOnRadar(sp::RenderTarget& renderer, sp::ecs::Entity entity, glm::vec2 screen_position, float scale, float rotation, BeamWeaponSys& beamsystem) override;
};
