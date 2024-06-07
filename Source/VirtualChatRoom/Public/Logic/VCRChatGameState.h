// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "VCRChatGameState.generated.h"

USTRUCT(BlueprintType)
struct FChatLog
{
    GENERATED_USTRUCT_BODY()

    FChatLog() {};

    FChatLog(FName NewPlayerName, FName NewMessage) : PlayerName(NewPlayerName), Message(NewMessage){}; 

    UPROPERTY()
    FName PlayerName;

    UPROPERTY()
    FName Message;
};

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnSendNewMessageSignature, const FString&, const FString&);

UCLASS()
class VIRTUALCHATROOM_API AVCRChatGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    void BroadcastNewMessage(const FString& PlayerName, const FString& MessageText);

    FOnSendNewMessageSignature OnSendNewMessageSignature;

    TArray<FChatLog> GetChatLog() const { return ChatLog; }

protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(Server, Unreliable)
    void ServerBroadcastNewMessage(const FString& PlayerName, const FString& MessageText);
    void ServerBroadcastNewMessage_Implementation(const FString& PlayerName, const FString& MessageText);

    UFUNCTION(NetMulticast, Unreliable)
    void MulticastBroadcastNewMessage(const FString& PlayerName, const FString& MessageText);
    void MulticastBroadcastNewMessage_Implementation(const FString& PlayerName, const FString& MessageText);

    UPROPERTY(Replicated)
    TArray<FChatLog> ChatLog;
};
