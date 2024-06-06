// This project is made for a test assignment

#include "UI/Widgets/InGame/VCRPlayersListWidget.h"
#include "Logic/VCRChatGameState.h"
#include "GameFramework/PlayerState.h"
#include "Player/VCRPlayerController.h"
#include "Components/ScrollBox.h"
#include "UI/Widgets/VCRTextWidget.h"
#include "Blueprint/WidgetTree.h"

UVCRPlayersListWidget::UVCRPlayersListWidget()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> FoundPlayerNameTextWidgetClass(TEXT("/Game/UI/WBP_BaseText"));

    PlayerNameTextWidgetClass = FoundPlayerNameTextWidgetClass.Class;

    SetVisibility(ESlateVisibility::Collapsed);
}

void UVCRPlayersListWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    const auto PlayerController = Cast<AVCRPlayerController>(GetOwningPlayer());
    if (!PlayerController) return;

    PlayerController->OnWantPlayersListSignature.AddUObject(this, &UVCRPlayersListWidget::ChangeVisibility);
}

void UVCRPlayersListWidget::ChangeVisibility(bool WidgetIsVisibile)
{
    SetVisibility(WidgetIsVisibile ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);

    if (!PlayersListBox) return;

    PlayersListBox->ClearChildren();

    TArray<FString> ReceivedPlayerNames = GetPlayersNames();

    for (int i = 0; i < ReceivedPlayerNames.Num(); ++i)
    {
        const auto CreatedPlayerNameWidget = WidgetTree->ConstructWidget<UVCRTextWidget>(PlayerNameTextWidgetClass);
        if (!CreatedPlayerNameWidget) continue;

        const auto PlayerName = FText::FromString(ReceivedPlayerNames[i]);

        CreatedPlayerNameWidget->SetWidgetText(PlayerName);

        PlayersListBox->AddChild(CreatedPlayerNameWidget);  // Not the best way. Because of the constant creation and destruction of widgets
                                                            // we can overflow memory
    }
}

TArray<FString> UVCRPlayersListWidget::GetPlayersNames() const
{
    if (!GetWorld()) return TArray<FString>();

    const auto GameState = Cast<AVCRChatGameState>(GetWorld()->GetGameState());
    if (!GameState) return TArray<FString>();

    TArray<FString> ReceivedPlayerNames;

    for (const auto OnePlayerState : GameState->PlayerArray)
    {
        if (!OnePlayerState) continue;

        ReceivedPlayerNames.Add(OnePlayerState->GetOldPlayerName());
    }

    return ReceivedPlayerNames;
}
