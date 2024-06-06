// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VCRPlayerController.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnSendNewMessageSignature, const FString&, const FString&);

UCLASS()
class VIRTUALCHATROOM_API AVCRPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    void SendMessage(const FString& PlayerName, const FString& MessageText);

    UFUNCTION()
    void OnNewMessageReceived(const FString& PlayerName, const FString& MessageText);

    FOnSendNewMessageSignature OnSendNewMessageSignature;

protected:
    virtual void SetupInputComponent() override;

    void OpenChat();

    UFUNCTION(Server, Unreliable)
    void ServerSendMessage(const FString& PlayerName, const FString& MessageText);
    void ServerSendMessage_Implementation(const FString& PlayerName, const FString& MessageText);

    UFUNCTION(Client, Unreliable)
    void ClientOnNewMessageReceived(const FString& PlayerName, const FString& MessageText);
    void ClientOnNewMessageReceived_Implementation(const FString& PlayerName, const FString& MessageText);
};
