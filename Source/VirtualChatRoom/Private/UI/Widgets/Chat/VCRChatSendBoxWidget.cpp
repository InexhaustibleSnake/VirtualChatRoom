// This project is made for a test assignment

#include "UI/Widgets/Chat/VCRChatSendBoxWidget.h"
#include "UI/Widgets/VCRMenuButton.h"
#include "Components/EditableTextBox.h"
#include "Player/VCRPlayerController.h"
#include "Logic/VCRGameInstance.h"

void UVCRChatSendBoxWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (SendTextButton)
    {
        SendTextButton->OnClicked.AddDynamic(this, &UVCRChatSendBoxWidget::SendMessage);
    }
}

void UVCRChatSendBoxWidget::SendMessage()
{
    const auto PlayerController = Cast<AVCRPlayerController>(GetOwningPlayer());
    if (!PlayerController) return;

    PlayerController->SendMessage(GetPlayerName().ToString(), GetMessageText().ToString());
}

FText UVCRChatSendBoxWidget::GetMessageText() const
{
    return ChatSendTextBlock ? ChatSendTextBlock->GetText() : FText();
}

FName UVCRChatSendBoxWidget::GetPlayerName() const
{
    const auto GameInstance = Cast<UVCRGameInstance>(GetGameInstance());

    return GameInstance ? GameInstance->GetPlayerName() : FName();
}
