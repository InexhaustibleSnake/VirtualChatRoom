// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VCRPlayerController.generated.h"

class AVCRChatGameState;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangePlayerListVisibility, bool);

UCLASS()
class VIRTUALCHATROOM_API AVCRPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    void SendMessage(const FString& PlayerName, const FString& MessageText);

    FOnChangePlayerListVisibility OnWantPlayersListSignature;

protected:
    AVCRChatGameState* GetChatGameState() const;

    virtual void SetupInputComponent() override;

    void OpenChat();

    void ChangePlayerListVisibility(bool IsVisible);

    UFUNCTION(Server, Unreliable)
    void ServerSendMessage(const FString& PlayerName, const FString& MessageText);
    void ServerSendMessage_Implementation(const FString& PlayerName, const FString& MessageText);
};
