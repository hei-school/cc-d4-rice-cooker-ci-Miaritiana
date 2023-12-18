// riceCooker.test.ts
import {
    Content,
    RiceCooker,
    getQuantity,
    setQuantity,
    getCapacity,
    setCapacity,
    getContent,
    setContent,
    getContentDetails,
    getTimer,
    setTimer,
    getTemperature,
    setTemperature,
    getCookingDuration,
    setCookingDuration,
    automaticCook,
    manualCook,
  } from './index';
  
  describe('Rice Cooker Functions', () => {
    describe('getQuantity', () => {
        it('should return the quantity of the content', () => {
            const content = new Content('Ingredient', 5);
            const result = getQuantity(content);
            expect(result).toBe(5);
        });
    });
  
    describe('setQuantity', () => {
        it('should set the quantity of the content', () => {
            const content = new Content('Ingredient', 5);
            setQuantity(content, 10);
            expect(content.quantity).toBe(10);
        });
    });
  
    describe('getCapacity', () => {
      it('should return the capacity of the rice cooker', () => {
        const riceCooker = new RiceCooker(10, new Content('', 0), 0, '', 0);
        const result = getCapacity(riceCooker);
        expect(result).toBe(10);
      });
    });
  
    describe('setCapacity', () => {
      it('should set the capacity of the rice cooker', () => {
        const riceCooker = new RiceCooker(10, new Content('', 0), 0, '', 0);
        setCapacity(riceCooker, 15);
        expect(riceCooker.capacity).toBe(15);
      });
    });
  
  });
  