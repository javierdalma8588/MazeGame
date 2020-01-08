#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Practica1GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICA1_API APractica1GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	//Create the cunstroctor of the class
	APractica1GameModeBase();

	//create the variable of picked objectives visible anywhere so it can be seen on the editor but not edited
	UPROPERTY(VisibleAnywhere)
		int pickedObjectives;

	//create the varibale of the amount of objectives to pick, available to edit on the editos
	UPROPERTY(EditAnywhere)
		int objectivesToPick;

	//create the function Tick
	void Tick(float deltaTime) override;
};
