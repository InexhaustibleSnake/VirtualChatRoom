// This project is made for a test assignment

#include "UI/Widgets/MainMenu/VCRMainMenuWidget.h"
#include "Components/WidgetSwitcher.h"
#include "UI/Widgets/VCRMenuButton.h"
#include "Kismet/KismetSystemLibrary.h"

void UVCRMainMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (CreateRoomButton)
    {
        CreateRoomButton->OnButtonClickedSignature.AddUObject(this, &UVCRMainMenuWidget::ChangeActiveWidget);
    }

    if (QuitGameButton)
    {
        QuitGameButton->OnClicked.AddDynamic(this, &UVCRMainMenuWidget::QuitGame);
    }
}

void UVCRMainMenuWidget::ChangeActiveWidget(UVCRMenuButton* MenuButton)
{
    if (!OnlineWidgetSwitcher || !WidgetSwitcherMap.Contains(MenuButton)) return;

    OnlineWidgetSwitcher->SetActiveWidget(WidgetSwitcherMap[MenuButton]);
}

void UVCRMainMenuWidget::QuitGame()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}
