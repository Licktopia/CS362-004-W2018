

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


//Jonathan Test add


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }
   
   
   public void testManualTest()
   {
      UrlValidator urlValidator = new UrlValidator();
      assert urlValidator.isValid("http://www.oregonstate.edu") == true;
      assertEquals(true, urlValidator.isValid("http://www.oregonstate.edu"));
//      assertEquals(false, urlValidator.isValid("rainbowsarepretty"));
//      assertEquals(true, urlValidator.isValid("oregonstate.edu"));

//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
      UrlValidator urlValidator = new UrlValidator();
	 //You can use this function to implement your First Partition testing	   
      assertEquals(false, urlValidator.isValid("rainbowsarepretty"));
   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
