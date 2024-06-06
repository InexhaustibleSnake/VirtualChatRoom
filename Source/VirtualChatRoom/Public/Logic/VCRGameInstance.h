// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VCRGameInstance.generated.h"

UCLASS()
class VIRTUALCHATROOM_API UVCRGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    void SetPlayerName(const FName NewName);
    FName GetPlayerName() const { return PlayerName; }

private:
    FName PlayerName;
};
