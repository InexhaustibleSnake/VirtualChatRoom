// This project is made for a test assignment

#include "Logic/VCRChatGameMode.h"
#include "UI/Widgets/InGame/VCRInGameHUDWidget.h"
#include "UI/VCRChatRoomHUD.h"
#include "Player/VCRPlayerCharacter.h"
#include "Logic/VCRChatGameState.h"

AVCRChatGameMode::AVCRChatGameMode()
{
    HUDClass = AVCRChatRoomHUD::StaticClass();
    DefaultPawnClass = AVCRPlayerCharacter::StaticClass();
    GameStateClass = AVCRChatGameState::StaticClass();
}
