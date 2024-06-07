// This project is made for a test assignment

#include "UI/Widgets/Chat/VCRChatContainerWidget.h"
#include "UI/Widgets/Chat/VCRChatMessage.h"
#include "Components/ScrollBox.h"
#include "Logic/VCRChatGameState.h"

UVCRChatContainerWidget::UVCRChatContainerWidget()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> FoundMessageWidgetClass(TEXT("/Game/UI/Chat/WBP_ChatMessage"));

    MessageWidget = FoundMessageWidgetClass.Class;
}

void UVCRChatContainerWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    const auto GameState = GetChatGameState();
    if (GameState)
    {
        GameState->OnSendNewMessageSignature.AddUObject(this, &UVCRChatContainerWidget::AddMessage);

        for (const auto OneLogData : GameState->GetChatLog())
        {
            AddMessage(OneLogData.PlayerName.ToString(), OneLogData.Message.ToString());
        }
    }
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

AVCRChatGameState* UVCRChatContainerWidget::GetChatGameState() const
{
    return GetWorld() ? Cast<AVCRChatGameState>(GetWorld()->GetGameState()) : nullptr;
}