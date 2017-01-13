// Copyright Matthias Drechsel 2017

#include "Escape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	// find the owning actor
	Owner = GetOwner();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

void UOpenDoor::OpenDoor() {

	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UOpenDoor::CloseDoor() {

	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the Trigger Volume every Frame
	// If the Actor that opnes is in the volume he 	OpenDoor();
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) {
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	//check if it is time to close
	TimeNow = GetWorld()->GetTimeSeconds();
	if (LastDoorOpenTime < (TimeNow - DoorCloseDelay)) {
		CloseDoor();
	}


}

