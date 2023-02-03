#pragma once

#include "scriptInterface.h"

class CommsReceiver
{
public:
    string script; // "comms_ship.lua" / "comms_station.lua"
    ScriptSimpleCallback callback;
};

class CommsTransmitter
{
public:
    enum class State
    {
        Inactive,          // No active comms
        OpeningChannel,    // Opening a comms channel
        BeingHailed,       // Receiving a hail from an object
        BeingHailedByGM,   //                   ... the GM
        ChannelOpen,       // Comms open to an object
        ChannelOpenPlayer, //           ... another player
        ChannelOpenGM,     //           ... the GM
        ChannelFailed,     // Comms failed to connect
        ChannelBroken,     // Comms broken by other side
        ChannelClosed      // Comms manually closed
    };
    struct ScriptReply
    {
        string message;
        ScriptSimpleCallback callback;
    };

    State state = State::Inactive;
    float open_delay = 0.0f;
    string target_name;
    string incomming_message;
    sp::ecs::Entity target; // Server only
    std::vector<ScriptReply> script_replies;
    
    //CommsScriptInterface
    bool has_message = false;
    P<ScriptObject> script_object;
};
