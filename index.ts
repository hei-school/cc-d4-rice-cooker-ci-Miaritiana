import * as promptSync from 'prompt-sync';

const prompt = promptSync();

export class Content {
  constructor(public name: string, public quantity: number) {}
}

export class RiceCooker {
  constructor(
    public capacity: number,
    public content: Content,
    public timer: number,
    public temperature: string,
    public cookingDuration: number
  ) {}
}

export function getName(c: Content): string {
  return c.name;
}

export function getQuantity(c: Content): number {
  return c.quantity;
}

export function setName(c: Content, newName: string): void {
  c.name = newName;
}

export function setQuantity(c: Content, newQuantity: number): void {
  c.quantity = newQuantity;
}

export function getCapacity(rc: RiceCooker): number {
  return rc.capacity;
}

export function setCapacity(rc: RiceCooker, newCapacity: number): void {
  rc.capacity = newCapacity;
}

export function getContent(rc: RiceCooker): Content {
  return rc.content;
}

export function setContent(rc: RiceCooker, newContent: Content): void {
  while (getQuantity(newContent) > getCapacity(rc)) {
    console.error("Out of capacity. Please enter a quantity within capacity: ");
  }

  rc.content = newContent;
}

export function getContentDetails(rc: RiceCooker): void {
  console.log(`This rice-cooker contains ${getQuantity(rc.content).toFixed(2)} kg of ${getName(rc.content)}`);
}

export function getTimer(rc: RiceCooker): number {
  return rc.timer;
}

export function setTimer(rc: RiceCooker, minute: number): void {
  rc.timer = minute;
  console.log(`Timer is set to ${minute} minutes`);
}

export function getTemperature(rc: RiceCooker): string {
  return rc.temperature;
}

export function setTemperature(rc: RiceCooker, setupTemperature: string): void {
  rc.temperature = setupTemperature;
  console.log(`Temperature set to ${setupTemperature}`);
}

export function getCookingDuration(rc: RiceCooker): number {
  return rc.cookingDuration;
}

export function setCookingDuration(rc: RiceCooker, minute: number): void {
  rc.cookingDuration = minute;
}

export function automaticCook(rc: RiceCooker): void {
  console.log("Starting automatic cooking...");
  console.log(`Cooking duration: ${getCookingDuration(rc)} minutes`);
  console.log(`Temperature: ${getTemperature(rc)}`);
  console.log("Automatic cooking completed!");
}

export function manualCook(rc: RiceCooker): void {
  console.log("Starting manual cooking...");
  console.log(`Temperature: ${getTemperature(rc)}`);
  console.log("Manual cooking completed!");
}

export function main(): void {
  let ingredient: string;
  let quantity: number;
  let capacity: number;

  console.log("Welcome to rice-cooker");
  capacity = parseFloat(prompt("Capacity: ") || "0");
  console.log("What are you going to cook?");
  ingredient = prompt("Ingredient: ") || "";
  quantity = parseFloat(prompt("Quantity: ") || "0");

  const riceCooker = new RiceCooker(capacity, new Content(ingredient, quantity), 0, "", 0);

  const choice: number = parseInt(prompt("1) Cook now\n2) Cook later\nEnter your choice: ") || "0");

  let choiceCook: number;

  switch (choice) {
    case 1: {
      console.log("1) Automatic cook\n2) Cook manually");
      choiceCook = parseInt(prompt("Enter your choice: ") || "0");

      switch (choiceCook) {
        case 1: {
          const cookingDuration: number = parseInt(prompt("Enter cooking duration (minutes): ") || "0");
          setCookingDuration(riceCooker, cookingDuration);

          const setupTemperature: string = prompt("Set temperature: ") || "";
          setTemperature(riceCooker, setupTemperature);
          automaticCook(riceCooker);
          break;
        }

        case 2: {
          const temperatureManual: string = prompt("Set temperature: ") || "";
          manualCook(riceCooker);
          break;
        }

        default:
          console.error("Invalid choice");
      }
      break;
    }

    case 2: {
      const minutes: number = parseInt(prompt("How many minutes does it take to start cooking?\nminutes: ") || "0");
      setTimer(riceCooker, minutes);

      console.log("1) Automatic cook\n2) Cook manually");
      choiceCook = parseInt(prompt("Enter your choice: ") || "0");

      switch (choiceCook) {
        case 1: {
          const cookingDuration: number = parseInt(prompt("Enter cooking duration (minutes): ") || "0");
          setCookingDuration(riceCooker, cookingDuration);

          const setupTemperature: string = prompt("Set temperature: ") || "";
          console.log(`Cooking starts at ${minutes} minutes later`);
          automaticCook(riceCooker);
          break;
        }

        case 2: {
          const temperatureManual: string = prompt("Set temperature: ") || "";
          console.log(`Cooking starts at ${minutes} minutes later`);
          manualCook(riceCooker);
          break;
        }

        default:
          console.error("Invalid choice");
      }
      break;
    }

    default:
      console.error("Invalid choice");
  }
}

main();
