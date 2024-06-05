// This project is made for a test assignment

#include "UI/Widgets/Chat/VCRChatMessage.h"
#include "Components/TextBlock.h"

void UVCRChatMessage::SetMessage(FText& MessageText) 
{
    SetTextBlockText(MessageTextBlock, MessageText);
}

void UVCRChatMessage::SetPlayerName(FText& PlayerName)
{
    SetTextBlockText(PlayerNameTextBlock, PlayerName);
}

void UVCRChatMessage::SetTextBlockText(UTextBlock* InTextBlock, FText& Text) 
{
    if (!InTextBlock) return;

    InTextBlock->SetText(Text);
}
