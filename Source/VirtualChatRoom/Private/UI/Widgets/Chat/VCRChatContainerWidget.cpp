// This project is made for a test assignment

#include "UI/Widgets/Chat/VCRChatContainerWidget.h"
#include "UI/Widgets/Chat/VCRChatMessage.h"
#include "Components/ScrollBox.h"

UVCRChatContainerWidget::UVCRChatContainerWidget() 
{
    static ConstructorHelpers::FClassFinder<UUserWidget> FoundMessageWidgetClass(TEXT("/Game/UI/Chat/WBP_ChatMessage"));

    MessageWidget = FoundMessageWidgetClass.Class;
}

void UVCRChatContainerWidget::AddMessage(const FString& PlayerName, const FString& Message)
{
    const auto NewMessage = CreateWidget<UVCRChatMessage>(this, MessageWidget);
    if (!NewMessage) return;

    NewMessage->SetPlayerName(FText::FromString(PlayerName));
    NewMessage->SetMessage(FText::FromString(Message));

    if (!ChatBox) return;

    ChatBox->AddChild(NewMessage);
}
