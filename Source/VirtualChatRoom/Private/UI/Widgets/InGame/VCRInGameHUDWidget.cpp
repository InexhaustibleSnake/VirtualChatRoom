// This project is made for a test assignment

#include "UI/Widgets/InGame/VCRInGameHUDWidget.h"
#include "UI/Widgets/Chat/VCRChatContainerWidget.h"
#include "Player/VCRPlayerController.h"

void UVCRInGameHUDWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    const auto PlayerController = Cast<AVCRPlayerController>(GetOwningPlayer());
    if (!PlayerController) return;

    PlayerController->OnSendNewMessageSignature.AddUObject(this, &UVCRInGameHUDWidget::OnNewMessageReceive);
}

void UVCRInGameHUDWidget::OnNewMessageReceive(const FString& PlayerName, const FString& Message) 
{
    if (!ChatWidget) return;
    ChatWidget->AddMessage(PlayerName, Message);
}
