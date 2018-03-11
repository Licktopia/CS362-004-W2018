

import com.oracle.tools.packager.Log;
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
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      int validUrlCounter = 0;
      List<String> validUrls = Arrays.asList("http://www.oregonstate.edu", "http://www.google.com");
      for(String url : validUrls) {
         if(urlValidator.isValid(url) == true){
            System.out.println(url + " Is valid");
            validUrlCounter++;
         }
         else {
            System.out.println(url + " Is not valid");
         }
      }
      assertEquals(validUrls.size(), validUrlCounter);
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
   
   public void testIsValid() {
      boolean noFailures = true;
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      for(String scheme : testSchemes) {
         for(String authority : testAuthorities) {
            for(String port : testPorts) {
               for(String path : testPaths) {
                  for(String query : testQueries) {
                     String url = scheme + authority + port + path + query;
                     boolean isValidUrl;
                     boolean validatorResult = false;
                     isValidUrl = validSchemes.contains(scheme) && validAuthorities.contains(authority) && validPorts.contains(port)
                             && validPaths.contains(path) && validQueries.contains(query);
                     try {
                        validatorResult = urlValidator.isValid(url);
                     }
                     catch (Error e) {
                        Log.debug("Url validator failure with exception: " + e);
                     }
                     if (isValidUrl != validatorResult) {
                        noFailures = false;
                        if (isValidUrl) {
                           System.out.println(url + " is valid but tested as invalid");
                        }
                        else {
                           String invalidText = findInvalidPart(scheme, authority, port, path, query);
                           System.out.println(url + " is not valid but tested as valid." + invalidText);
                        }

                     }
                  }
               }
            }
         }
      }
      assertEquals(true, noFailures);
   }

   String findInvalidPart(String scheme, String authority, String port, String path, String query) {
      String text = " Invalid Parts: (";
      if(!validSchemes.contains(scheme)) {
         text = text + "scheme: " + scheme + ", ";
      }
      if(!validAuthorities.contains(authority)) {
         text = text + "authority: " + authority + ", ";
      }
      if(!validPorts.contains(port)) {
         text = text + "port: " + port + ", ";
      }
      if(!validPaths.contains(path)) {
         text = text + "path: " + path + ", ";
      }
      if(!validQueries.contains(query)) {
         text = text + "query: " + query;
      }
      text = text + ")";
      return text;
   }

   private List<String> validSchemes = Arrays.asList("http://", "https://", "ftp://", "");
   private List<String> testSchemes = Arrays.asList("http://", "https://", "ftp://", "", "abc", "test://", "http:/");
   private List<String> validAuthorities = Arrays.asList("www.cool.com", "cool.com", "cool.edu", "www.cool.org");
   private List<String> testAuthorities = Arrays.asList("www.cool.com", "cool.com", "cool.edu", "www.cool.org", "cool", "", "cool.");
   private List<String> validPorts = Arrays.asList(":8080", ":0", "", ":35656");
   private List<String> testPorts = Arrays.asList("", ":8080", ":0", ":35656", ":-8080", ":abc", ":78010");
   private List<String> validPaths = Arrays.asList("/image", "", "/image/image", "/1test");
   private List<String> testPaths = Arrays.asList("/image", "", "/image/image", "/1test", "/#", "/&#", "/#&*");
   private List<String> validQueries = Arrays.asList("?test=true", "", "?test=true&test1=false", "?cool=5");
   private List<String> testQueries = Arrays.asList("?test=true", "", "?test=true&test1=false", "?cool=5", "#", "?test#5", "###");


}
