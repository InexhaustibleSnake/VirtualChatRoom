// This project is made for a test assignment

#include "Player/VCRMainMenuPlayerController.h"

void AVCRMainMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    SetShowMouseCursor(true);

    SetInputMode(FInputModeUIOnly());
}
