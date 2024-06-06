// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "VCRChatGameState.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnSendNewMessageSignature, const FString&, const FString&);

UCLASS()
class VIRTUALCHATROOM_API AVCRChatGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    void BroadcastNewMessage(const FString& PlayerName, const FString& MessageText);

    FOnSendNewMessageSignature OnSendNewMessageSignature;

protected:
    UFUNCTION(Server, Unreliable)
    void ServerBroadcastNewMessage(const FString& PlayerName, const FString& MessageText);
    void ServerBroadcastNewMessage_Implementation(const FString& PlayerName, const FString& MessageText);

    UFUNCTION(NetMulticast, Unreliable)
    void MulticastBroadcastNewMessage(const FString& PlayerName, const FString& MessageText);
    void MulticastBroadcastNewMessage_Implementation(const FString& PlayerName, const FString& MessageText);
};
