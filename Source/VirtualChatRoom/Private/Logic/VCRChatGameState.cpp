// This project is made for a test assignment

#include "Logic/VCRChatGameState.h"
#include "Net/UnrealNetwork.h"

void AVCRChatGameState::BroadcastNewMessage(const FString& PlayerName, const FString& MessageText)
{
    if (!HasAuthority())
    {
        ServerBroadcastNewMessage(PlayerName, MessageText);
        return;
    }

    FChatLog NewChatData = FChatLog(FName(PlayerName), FName(MessageText));
    ChatLog.Add(NewChatData);

    MulticastBroadcastNewMessage(PlayerName, MessageText);
}

void AVCRChatGameState::ServerBroadcastNewMessage_Implementation(const FString& PlayerName, const FString& MessageText)
{
    BroadcastNewMessage(PlayerName, MessageText);
}

void AVCRChatGameState::MulticastBroadcastNewMessage_Implementation(const FString& PlayerName, const FString& MessageText) 
{
    OnSendNewMessageSignature.Broadcast(PlayerName, MessageText);
}

void AVCRChatGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION(AVCRChatGameState, ChatLog, COND_InitialOnly);
}