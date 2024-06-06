// This project is made for a test assignment

#include "Player/VCRPlayerState.h"
#include "Logic/VCRGameInstance.h"

void AVCRPlayerState::BeginPlay()
{
    Super::BeginPlay();

    if (HasLocalNetOwner())
    {
        InitPlayerName(GetPlayerName());
    }
}

void AVCRPlayerState::InitPlayerName(FName NewPlayerName)
{
    if (!HasAuthority())
    {
        ServerInitPlayerName(GetPlayerName());
        return;
    }

    SetPlayerName(NewPlayerName.ToString());
}

void AVCRPlayerState::ServerInitPlayerName_Implementation(FName NewPlayerName)
{
    InitPlayerName(NewPlayerName);
}

FName AVCRPlayerState::GetPlayerName() const
{
    const auto GameInstace = Cast<UVCRGameInstance>(GetGameInstance());

    return GameInstace ? GameInstace->GetPlayerName() : FName();
}
