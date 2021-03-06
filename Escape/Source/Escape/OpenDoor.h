// Copyright Matthias Drechsel 2017

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
private:
	UPROPERTY(EditAnywhere) //VisibleAnywhere
	float OpenAngle = 90.0f;
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;
	//UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens; //(Remember pawn inherits from actor )
	AActor* Owner; //The owning Door

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.0f;

	float LastDoorOpenTime;
	float TimeNow;



};
