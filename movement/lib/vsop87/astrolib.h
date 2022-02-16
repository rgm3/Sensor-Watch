/*
 * Partial C port of Greg Miller's public domain astro library (gmiller@gregmiller.net) 2019
 * https://github.com/gmiller123456/astrogreg *
 *
 * Public Domain
 *
 * THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ASTROLIB_H_
#define ASTROLIB_H_

typedef enum {
    ASTRO_BODY_SUN = 0,
    ASTRO_BODY_MERCURY,
    ASTRO_BODY_VENUS,
    ASTRO_BODY_EARTH,
    ASTRO_BODY_MARS,
    ASTRO_BODY_JUPITER,
    ASTRO_BODY_SATURN,
    ASTRO_BODY_URANUS,
    ASTRO_BODY_NEPTUNE,
    ASTRO_BODY_EMB,
    ASTRO_BODY_MOON
} astro_body_t;

typedef struct {
    double elements[3][3];
} astro_matrix_t;

typedef struct {
    double x;
    double y;
    double z;
} astro_cartesian_coordinates_t;

typedef struct {
    double right_ascension;
    double declination;
    double distance;
} astro_equatorial_coordinates_t;

typedef struct {
    double altitude;
    double azimuth;
} astro_horizontal_coordinates_t;

astro_equatorial_coordinates_t astro_get_ra_dec(double jd, astro_body_t bodyNum, double lat, double lon, bool calculate_precession);
astro_horizontal_coordinates_t astro_ra_dec_to_alt_az(double jd, double lat, double lon, double ra, double dec);

#endif // ASTROLIB_H_
