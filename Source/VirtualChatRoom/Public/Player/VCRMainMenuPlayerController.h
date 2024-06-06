// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VCRMainMenuPlayerController.generated.h"

UCLASS()
class VIRTUALCHATROOM_API AVCRMainMenuPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;
};
