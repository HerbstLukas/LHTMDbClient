LHTMDbClient
==============


- LHTMDbClient is an iOS wrapper on top of AFNetworking to interact with [themoviedb.org](www.themoviedb.org) API.
- This project is forked from Javi Lorbada - [JLTMDbClient](https://github.com/JaviLorbada/JLTMDbClient)

## Installation: ##

- The best way to get LHTMDbClient is by using [CocoaPods](http://cocoapods.org/). 
- [How to install CocoaPods](https://speakerdeck.com/javilorbada/introduction-to-cocoapods?slide=13)

## Demo App:
<br>
Not done yet. Will follow.

## Usage: ##

1. Get your API KEY from [themoviedb.org](http://www.themoviedb.org/documentation/api)

> "A TMDb user account is required to request an API key. Commercial users are approved on a per application basis. As always, you must attribute TMDb as the source of your data. Please be sure to read the [API FAQ](http://www.themoviedb.org/faq/api)"

2. Add LHTMDbClient to your application, and set up your API KEY in the AppDelegate - didFinishLaunchingWithOptions.

```
#import <LHTMDbClient.h>
```

```
[[LHTMDbClient sharedAPIInstance] setAPIKey:@"API_KEY"];
```
3. Call a service to get the response from the server *, i.e:


```
[[LHTMDbClient sharedAPIInstance] GET:kLHTMDbMoviePopular withParameters:nil andResponseBlock:^(id response, NSError *error) {
    if(!error){
        fetchedData = response;
        NSLog(@"Popular Movies: %@",fetchedData);
    }
}];
```
- When you want to get a specifik episode of an season you can do it like this: 

```
    [[LHTMDbClient sharedAPIInstance] GET:kLHTMDbTV withParameters:@{@"id":self.showId ,@"season_number":self.seasonNr, @"episode_number":self.episodeNr} andResponseBlock:^(id response, NSError *error)
    {
        if (!error)
        {
            self.tvShwoData = response;
            NSLog(@"%@", self.tvShwoData);
        } else
        {
            NSLog(@"%@", error);
        }
    }];
```
Options have to be NSStrings - and you have to use the IDs @"id", @"season_number" and @"episode_number". <br>
See the Table of contents which request require which options. <br>
If there are any questions please contact me.

* [Table of contents](https://github.com/HerbstLukas/LHTMDbClient/blob/master/LHTMDbClient/LHTMDbClientDefines.h)


## Compatibility: ##

- Compatible with [iOS 7.0](https://developer.apple.com/library/ios/releasenotes/General/WhatsNewIniOS/Articles/iOS7.html).
- Does require ARC. 

## Dependencies: ##

- [AFNetworking](https://github.com/AFNetworking/AFNetworking) 2.0.0 or superior.

## License: ##

- LHTMDbClient is released under a [MIT-License](http://opensource.org/licenses/MIT). See [License](https://github.com/JaviLorbada/LHTMDbClient/blob/master/LICENSE) file for more info.

## Credits: ##

- Thanks to [Javi Lorbada](https://github.com/fjcaetano) and his project [JLTMDbClient](https://github.com/JaviLorbada/JLTMDbClient)
- Thanks to [themoviedb.org](http://themoviedb.org) for the awesome API <3.

## Contact: ##

- [Lukas Herbst](mailto:lukas.herbst@me.com) 
- Follow [@HerbstLukas](https://twitter.com/HerbstLukas) on twitter
- [http://lks.is](http://lks.is/)


