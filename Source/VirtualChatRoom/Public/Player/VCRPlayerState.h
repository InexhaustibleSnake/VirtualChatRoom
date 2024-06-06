// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "VCRPlayerState.generated.h"

UCLASS()
class VIRTUALCHATROOM_API AVCRPlayerState : public APlayerState
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

    void InitPlayerName(FName NewPlayerName);

    UFUNCTION(Server, Unreliable)
    void ServerInitPlayerName(FName NewPlayerName);
    void ServerInitPlayerName_Implementation(FName NewPlayerName);

    FName GetPlayerName() const;
};
