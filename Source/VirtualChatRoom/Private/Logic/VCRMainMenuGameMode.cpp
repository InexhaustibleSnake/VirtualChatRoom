// This project is made for a test assignment

#include "Logic/VCRMainMenuGameMode.h"
#include "UI/VCRMainMenuHUD.h"
#include "Player/VCRMainMenuPlayerController.h"

AVCRMainMenuGameMode::AVCRMainMenuGameMode()
{
    HUDClass = AVCRMainMenuHUD::StaticClass();
    PlayerControllerClass = AVCRMainMenuPlayerController::StaticClass();
}
