// This project is made for a test assignment

#include "Logic/VCRBaseGameMode.h"
#include "Player/VCRPlayerCharacter.h"

AVCRBaseGameMode::AVCRBaseGameMode()
{
    DefaultPawnClass = AVCRPlayerCharacter::StaticClass();
}
