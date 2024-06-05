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
    void ServerBroadcastNewMesssage(const FString& PlayerName, const FString& MessageText);
    void ServerBroadcastNewMesssage_Implementation(const FString& PlayerName, const FString& MessageText);

    UFUNCTION(NetMulticast, Unreliable)
    void MulticastBroadcastNewMesssage(const FString& PlayerName, const FString& MessageText);
    void MulticastBroadcastNewMesssage_Implementation(const FString& PlayerName, const FString& MessageText);
};
