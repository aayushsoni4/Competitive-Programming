import requests

def asteroidOrbit(year, orbitclass):
    base_url = "https://jsonmock.hackerrank.com/api/asteroids/search?"
    endpoint = f"{base_url}orbit_class={orbitclass}&page="
    designations = []
    page_num = 1
    total_pages = 1

    while page_num <= total_pages:
        response = requests.get(endpoint + str(page_num))
        response = response.json()

        total_pages = response["total_pages"]

        for asteroid in response["data"]:
            if str(year) in asteroid['discovery_date']:
                if orbitclass.lower() in asteroid['orbit_class'].lower():
                    period_yr = 1
                    try:
                        period_yr = float(asteroid['period_yr'])
                    except:
                        pass
                    
                    designations.append((period_yr,asteroid['designation']))
        
        if total_pages <= page_num:
            break
        page_num += 1

    designations.sort(key=lambda x: (x[0],x[1]))
    
    result = []
    for _, designation in designations:
        result.append(f"{designation}")
    return result

# Example usage:
year_of_discovery = 2010
orbit_class_keyword = "aten"
result = asteroidOrbit(year_of_discovery, orbit_class_keyword)
for i in result:
    print(i)
