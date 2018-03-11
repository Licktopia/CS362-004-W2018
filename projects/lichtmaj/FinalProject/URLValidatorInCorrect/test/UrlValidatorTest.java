

import junit.framework.TestCase;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


//Jonathan Test add
//Jeff Test add


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }
   
   
   public void testManualTest()
   {
      UrlValidator urlValidator = new UrlValidator();

      List<String> validUrls = Arrays.asList("http://www.oregonstate.edu", "www.oregonstate.edu");
      for(String url : validUrls) {
         if(urlValidator.isValid(url) == true){
            System.out.println(url + " Is valid");
         }
         else {
            System.out.println(url + " Is not valid");
         }
      }
      

      assertEquals(true, urlValidator.isValid("http://www.oregonstate.edu"));
      assertEquals(true, urlValidator.isValid("http://www.oregonstate.com"));
      assertEquals(true, urlValidator.isValid("www.oregonstate.edu"));
      assertEquals(true, urlValidator.isValid("oregonstate.edu"));
//      assertEquals(true, urlValidator.isValid("http://www.oregonstate.edu"));
//      assertEquals(false, urlValidator.isValid("rainbowsarepretty"));
//      assertEquals(true, urlValidator.isValid("oregonstate.edu"));
      
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
