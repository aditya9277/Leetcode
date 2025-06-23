# Write your MySQL query statement below



-- char_length function must be used for calculating the length of string
-- length functions works for normal characters, but it fails in cas of unicode
-- if string contains unicode character like '€', it will fail
-- thats whar char_length counts only the characters

select tweet_id from Tweets where LENGTH(content)>15