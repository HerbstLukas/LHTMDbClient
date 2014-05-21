//
//  LHTMDbClientDefines.h
//  TheMovieDB
//
//  Created by Lukas Herbst on 21.05.14.
//  Copyright (c) 2014 Lukas Herbst All rights reserved.
//  http://lks.is
//

#import "LHTMDbClient.h"

//The Complete Documentation can be found here: http://docs.themoviedb.apiary.io/

#pragma mark - API URL
static NSString * const kLHTMDbAPISSL = @"https";
static NSString * const kLHTMDbAPINoSSL = @"http";
static NSString * const kLHTMDbAPIBaseURL = @"://api.themoviedb.org/";
static NSString * const kLHTMDbAPIVersion = @"3/";

#pragma mark - Configuration
//Documentation: http://docs.themoviedb.apiary.io/#configuration
static NSString * const kLHTMDbConfiguration = @"configuration";

#pragma mark - Movies
//Documentation: http://docs.themoviedb.apiary.io/#movies
static NSString * const kLHTMDbMovie = @"movie/{id}";
static NSString * const kLHTMDbMovieAlternativeTitle = @"movie/{id}/alternative_titles";
static NSString * const kLHTMDbMovieCasts = @"movie/{id}/casts";
static NSString * const kLHTMDbMovieImages = @"movie/{id}/images";
static NSString * const kLHTMDbMovieKeywords = @"movie/{id}/keywords";
static NSString * const kLHTMDbMovieReleases = @"movie/{id}/releases";
static NSString * const kLHTMDbMovieTrailers = @"movie/{id}/trailers";
static NSString * const kLHTMDbMovieTranslations = @"movie/{id}/translations";
static NSString * const kLHTMDbMovieSimilar = @"movie/{id}/similar_movies";
static NSString * const kLHTMDbMovieReviews = @"movie/{id}/reviews";
static NSString * const kLHTMDbMovieLists = @"movie/{id}/lists";
static NSString * const kLHTMDbMovieChanges = @"movie/{id}/changes";
static NSString * const kLHTMDbMovieLatest = @"movie/latest";
static NSString * const kLHTMDbMovieUpcoming = @"movie/upcoming";
static NSString * const kLHTMDbMovieNowPlaying = @"movie/now_playing";
static NSString * const kLHTMDbMoviePopular = @"movie/popular";
static NSString * const kLHTMDbMovieTopRated = @"movie/top_rated";

#pragma mark - TV-Shows
//Documentation:http://docs.themoviedb.apiary.io/#tv
static NSString * const kLHTMDbTV = @"tv/{id}";
static NSString * const kLHTMDbTVChanges = @"tv/{id}/changes";
static NSString * const kLHTMDbTVCredits = @"tv/{id}/credits";
static NSString * const kLHTMDbTVExternalIDs = @"tv/{id}/external_ids";
static NSString * const kLHTMDbTVImages = @"tv/{id}/images";
static NSString * const kLHTBDbTVPlotKeywords = @"tv/{id}/keywords";
static NSString * const kLHTBDbTVSimilar = @"tv/{id}/similar";
static NSString * const kLHTBDbTVTranslations = @"tv/{id}/translations";
static NSString * const kLHTBDbTVVideos = @"tv/{id}/videos";
static NSString * const kLHTBDbTVOnTheAir = @"tv/on_the_air";
static NSString * const kLHTBDbTVAiringToday = @"airing_today";
static NSString * const kLHTBDbTVTopRated = @"tv/top_rated";
static NSString * const kLHTBDbTVPopular = @"tv/popular";

#pragma mark - TV-Show Seasons
//Documentation: http://docs.themoviedb.apiary.io/#tvseasons
static NSString * const kLHTMDbTVShowSeason = @"tv/{id}/season/{season_number}";
static NSString * const kLHTMDbTVShowChanges = @"tv/season/{id}/changes";
static NSString * const kLHTMDbTVShowSeasonCredits = @"tv/{id}/season/{season_number}/credits";
static NSString * const kLHTMDbTVShowSeasonExternalIDs = @"tv/{id}/season/{season_number}/external_ids";
static NSString * const kLHTMDbTVShowSeasonImages = @"tv/{id}/season/{season_number}/images";
static NSString * const kLHTMDbTVShowSeasonVideos = @"tv/{id}/season/{season_number}/videos";

#pragma mark - TV-Show Season - Episodes
//Documentation: http://docs.themoviedb.apiary.io/#tvepisodes
static NSString * const kLHTMDbTVShowSeasonEpisode = @"tv/{id}/season/{season_number}/episode/{episode_number}";
static NSString * const kLHTMDbTVShowSeasonEpisodeChanges = @"tv/episode/{id}/changes";
static NSString * const kLHTMDbTVShowSeasonEpisodeCredits = @"tv/{id}/season/{season_number}/episode/{episode_number}/credits";
static NSString * const kLHTMDbTVShowSeasonEpisodeEyternalIDs = @"tv/{id}/season/{season_number}/episode/{episode_number}/external_ids";
static NSString * const kLHTMDbTVShowSeasonEpisodeImages = @"tv/{id}/season/{season_number}/episode/{episode_number}/images";
static NSString * const kLHTMDbTVShowSeasonEpisodeVideos = @"tv/{id}/season/{season_number}/episode/{episode_number}/videos";

#pragma mark - People
//Documentation: http://docs.themoviedb.apiary.io/#people
static NSString * const kLHTMDbPerson = @"person/{id}";
static NSString * const kLHTMDbPersonCredits = @"person/{id}/credits";
static NSString * const kLHTMDbPersonImages = @"person/{id}/images";
static NSString * const kLHTMDbPersonChanges = @"person/{id}/changes";
static NSString * const kLHTMDbPersonPopular = @"person/popular";
static NSString * const kLHTMDbPersonLatest = @"person/latest";

#pragma mark - Companies
//Documentation: http://docs.themoviedb.apiary.io/#companies
static NSString * const kLHTMDbCompany = @"company/{id}";
static NSString * const kLHTMDbCompanyMovies = @"company/{id}/movies";

#pragma mark - Genres
//Documentation: http://docs.themoviedb.apiary.io/#genres
static NSString * const kLHTMDbGenreList = @"genre/list";
static NSString * const kLHTMDbGenreMovies = @"genre/{id}/movies";

#pragma mark - Keywords
//Documentation: http://docs.themoviedb.apiary.io/#keywords
static NSString * const kLHTMDbKeyword = @"keyword/{id}";
static NSString * const kLHTMDbKeywordMovies = @"keyword/{id}/movies";

#pragma mark - Search
//Documentation: http://docs.themoviedb.apiary.io/#search
static NSString * const kLHTMDbSearchMovie = @"search/movie";
static NSString * const kLHTMDbSearchTVShow = @"search/tv";
static NSString * const kLHTMDbSearchCollection = @"search/collection";
static NSString * const kLHTMDbSearchList = @"search/list";
static NSString * const kLHTMDbSearchPerson = @"search/person";
static NSString * const kLHTMDbSearchCompany = @"search/company";


