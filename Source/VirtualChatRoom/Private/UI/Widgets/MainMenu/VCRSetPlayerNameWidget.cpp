// This project is made for a test assignment

#include "UI/Widgets/MainMenu/VCRSetPlayerNameWidget.h"
#include "UI/Widgets/VCRMenuButton.h"
#include "Logic/VCRGameInstance.h"
#include "Components/EditableTextBox.h"

void UVCRSetPlayerNameWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (SaveNameButton)
    {
        SaveNameButton->OnClicked.AddDynamic(this, &UVCRSetPlayerNameWidget::SavePlayerName);
    }
}

void UVCRSetPlayerNameWidget::SavePlayerName()
{
    const auto PlayerName = GetTextBoxPlayerName();
    if (PlayerName.IsNone()) return;

    const auto GameInstance = Cast<UVCRGameInstance>(GetGameInstance());
    if (!GameInstance) return;

    GameInstance->SetPlayerName(PlayerName);

    RemoveFromParent();
}

FName UVCRSetPlayerNameWidget::GetTextBoxPlayerName() const
{
    if (!SetNameTextBox) return FName();

    FName PlayerName = FName(SetNameTextBox->GetText().ToString());

    return PlayerName;
}
